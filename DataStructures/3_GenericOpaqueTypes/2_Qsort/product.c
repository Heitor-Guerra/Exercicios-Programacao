#include "product.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE "VALOR INVALIDO\n"
#define ERROR_QUANTITY "QUANTIDADE INVALIDA\n"
#define ERROR_MESSAGE "ESTOQUE INSUFICIENTE\n"


struct product {
    char name[64];
    float price;
    float discount;
    int qtd;
    int sales;
};

Product *product_constructor(const char *name, float price, int qtd) {
    if(price < 0 || qtd < 0) {
        printf(ERROR_VALUE);
        return NULL;
    }

    Product *p = (Product*)malloc(sizeof(Product));

    strncpy(p->name, name, strlen(name) + 1);
    p->price = price;
    p->qtd = qtd;
    p->sales = 0;
    p->discount = 0;

    return p;
}

const char *product_get_name(Product *product) {
    return product->name;
}
float product_get_price(Product *product) {
    return product->price;
}
float product_get_discount(Product *product) {
    return product->discount;
}
int product_get_qtd(Product *product) {
    return product->qtd;
}
int product_get_sales(Product *product) {
    return product->sales;
}

void product_set_name(Product *product, const char *name) {
    strncpy(product->name, name, strlen(name) + 1);
}
void product_set_price(Product *product, float price) {
    if(price <= 0) {
        printf(ERROR_VALUE);
        return;
    }
    product->price = price;
}
void product_set_discount(Product *product, float discount) {
    if(discount < 0 || discount > 1) {
        printf(ERROR_VALUE);
        return;
    }
    product->discount = discount;
}

void product_sell(Product *product, int quantity) {
    if(quantity > product->qtd) {
        printf(ERROR_MESSAGE);
        return;
    } else if(quantity < 0) {
        printf(ERROR_QUANTITY);
        return;
    }
    product->sales += quantity;
    product->qtd -= quantity;
}
void product_buy(Product *product, int quantity) {
    if(quantity < 0) {
        printf(ERROR_QUANTITY);
        return;
    }
    product->qtd += quantity;
}

float product_get_price_with_discount(Product *product) {
    return product->price * (1.0-product->discount);
}
void product_print(Product *product) {
    printf("Product(%s, %.2f, %.2f, %.2f, %d, %d)\n", product->name, product->price, product->discount, product_get_price_with_discount(product), product->qtd, product->sales);
}


int product_compare_price(const void *p1, const void *p2) {
    Product *pr1 = *((Product**)p1);
    Product *pr2 = *((Product**)p2);

    if(pr1->price - pr2->price < 0) {
        return -1;
    } else if(pr1->price - pr2->price == 0) {
        return 0;
    }
    return 1;
}

int product_compare_name(const void *p1, const void *p2) {
    Product *pr1 = *((Product**)p1);
    Product *pr2 = *((Product**)p2);

    return strcmp(pr1->name, pr2->name);
}

int product_compare_sales(const void *p1, const void *p2) {
    Product *pr1 = *((Product**)p1);
    Product *pr2 = *((Product**)p2);

    return pr1->sales - pr2->sales;
}

void product_destructor(Product *product) {
    free(product);
}
