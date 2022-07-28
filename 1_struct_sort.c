#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Product {
    unsigned int id;
    float price;
    unsigned short sales_count;
    char name[10];
} Product;

// Array of product names
char *names_list[] = {
    "product1",
    "product2",
    "product3",
    "product4",
    "product5"
};
// Function that initializes product with random values
void init_random_product(Product *p) {
    static int id_counter = 0;
    p->id = id_counter++;

    // (150 + rand()%(20025 - 150)) - NUMBER IN RANGE [150,20025)
    // (150 + rand()%(20025 - 150))/100.   - NUMBER IN RANGE [1.5, 200.25)
    p->price = (150 + rand()%(20025 - 150))/100.;
    p->sales_count = rand()%1000;

    // Copy string from names_list
    strcpy(p->name, names_list[rand()%5]);
}
// Print info for given product
void print_product(Product *p) {
    printf("Revenue:%f, id:%d, price:%f, Sales Count: %d, Name:%s\n",
        p->price*p->sales_count, p->id, p->price, p->sales_count, p->name);
}
// Comparator function for custom sorting
int compare_products(const void *p1, const void *p2) {
    const Product *prod1 = p1, *prod2 = p2;
    double sales_diff = prod1->price*prod1->sales_count -
                        prod2->price*prod2->sales_count;

    // If the product have a big difference in sales_count*price
    if(fabs(sales_diff) > 0.01) {
        // If sales_diff < 0 - then product1 will be sorted before product2
        // If sales_diff > 0 - then product2 will be sorted before product1
        return sales_diff*100;
    }
    // Else we consider the two product to have the same sales_count*price
    // We have to compare names instead
    int cmp_res = strcmp(prod1->name, prod2->name);
    // If product1.name is different from product2.name
    if(cmp_res != 0) {
        // If cmp_res < 0 then product1 will be sorted before product2
        // If cmp_res > 0 then product2 will be sorted before product1
        return cmp_res;
    }
    // Else product1.name is equal to product2.name

    // We have to compare product id's
    return prod1->id - prod2->id;
}

int main() {
    // Srote products in dynamic memory
    Product *product_list;
    product_list = malloc(30*sizeof(Product));
    if(!product_list) {
        perror("Malloc failed\n");
        return -1;
    }

    srand(time(NULL));

    // Init random product values
    for(int i = 0; i < 30; i++) {
        init_random_product(product_list + i);
    }

    // Test if all sorting criteria work
    product_list[0].sales_count = 0;
    product_list[0].price = 0;
    product_list[1].sales_count = 0;
    product_list[1].price= 0;
    product_list[2].sales_count = 0;
    product_list[2].price = 0;
    product_list[3].sales_count = 0;
    product_list[3].price = 0;
    product_list[4].sales_count = 0;
    product_list[4].price = 0;

    qsort(product_list, 30, sizeof(Product), compare_products);

    // Print sorted products
    for(int i = 0; i < 30; i++) {
        print_product(product_list + i);
    }
    free(product_list);
}