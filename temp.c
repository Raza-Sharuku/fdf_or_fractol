#include <mlx.h>
#include <stddef.h>

char *img_addr;
void put_pixel_in_img(char **img_addr, int size_line, int x, int y)
{
    int color = 0xff4433;
    (*img_addr)[x * 4 + y * size_line + 0] = (color >> 16) & 0xff;
    (*img_addr)[x * 4 + y * size_line + 1] = (color >> 8) & 0xff;
    (*img_addr)[x * 4 + y * size_line + 2] = color & 0xff;
    (*img_addr)[x * 4 + y * size_line + 3] = 0x00;
}

int main() {
    void *mlx;
    mlx = mlx_init();
    void *window;
    window = mlx_new_window(mlx, 500, 500, "hoge");
    void *img = mlx_new_image(mlx, 500, 500);
    int size_line, bit_per_pixel, endian;
    printf("bit_per_pixel : %d\n", bit_per_pixel);
    printf("size_line : %d\n", size_line );
    printf("endian : %d\n", endian);

    img_addr = mlx_get_data_addr(img, &bit_per_pixel, &size_line, &endian);

    printf("bit_per_pixel : %d\n", bit_per_pixel);
    printf("size_line : %d\n", size_line );
    printf("endian : %d\n", endian);


    for (size_t i = 100; i < 200; i++)
    {
        for (size_t j = 0; j < 500 ; j++)
        {
            put_pixel_in_img(&img_addr ,size_line, j, i);
        }
    }
    

    
    mlx_put_image_to_window(mlx, window, img, 0, 0);
    mlx_loop(mlx);

    
    return 0;
}