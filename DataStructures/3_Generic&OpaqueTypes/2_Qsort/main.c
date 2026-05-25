

#include <stdio.h>
#include <stdlib.h>
#include "product.h"

Product *create_product()
{
    char name[128];
    float price;
    int qtd;
    int sales;

    scanf("%[^\n]\n", name);
    scanf("%f\n", &price);
    scanf("%d\n", &qtd);
    scanf("%d\n", &sales);



    Product* p = product_constructor(name, price, qtd);
    product_sell(p, sales);
    return p;
}

// void perform_operation(Product *product)
// {
//     char name[128];
//     float price, discount;
//     int qtd;
//     char operation;

//     scanf("\n%c", &operation);

//     if (operation == 'P')
//         product_print(product);
//     else if (operation == 'S')
//     {
//         scanf("\n%d", &qtd);
//         product_sell(product, qtd);
//     }
//     else if (operation == 'B')
//     {
//         scanf("\n%d", &qtd);
//         product_buy(product, qtd);
//     }
//     else if (operation == 'D')
//     {
//         scanf("\n%f", &discount);
//         product_set_discount(product, discount);
//     }
//     else if (operation == 'Q')
//     {
//         scanf("\n%f", &price);
//         product_set_price(product, price);
//     }
//     else if (operation == 'N')
//     {
//         scanf("\n%[^\n]\n", name);
//         product_set_name(product, name);
//     }
//     else
//         printf("Operacao invalida.\n");
// }



int main()
{
    char op;
    int n_operations;
    scanf("%d\n", &n_operations);

    Product *products[n_operations];

    for (int i = 0; i < n_operations; ++i) {
        products[i] = create_product();

    }

    scanf("%c", &op);
    switch (op) {
    case 'N':
        qsort(products, n_operations, sizeof(Product*), product_compare_name);
        break;
    case 'P':
        qsort(products, n_operations, sizeof(Product*), product_compare_price);
        break;
    case 'S':
        qsort(products, n_operations, sizeof(Product*), product_compare_sales);
        break;
    }
    


    for (int i = 0; i < n_operations; ++i) {
        product_print(products[i]);
        product_destructor(products[i]);
    }

    return 0;
}
