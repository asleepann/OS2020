#include <stdio.h>

struct page {
    int id;
    int r_bit;
    int age;
};

#define n 10 // number of page frames
struct page pages[n]; // array of pages

int main() {
    FILE *input = fopen("ex1_input.txt", "r");
    
    // fill the array of pages with initial values
    for (int i = 0; i < n; i++) {
        struct page p;
        p.id = 0;
        p.r_bit = 0;
        p.age = 0;
        pages[i] = p;
    }

    int find_id; // id of the page that is need to be referenced
    int hit = 0;
    int miss = 0;
    while (fscanf(input, "%d", &find_id) != EOF) { // read while file is not ended
        int i_in_pages = -1; // i of needed page in array pages; -1 if needed page is not in array

        // find page in array of pages
        for (int i = 0; i < n; i++) {
            if (pages[i].id == find_id) {
                i_in_pages = i;
                pages[i].r_bit = 1;
                hit++;
                break;
            }
        }

        // if needed page is not in array pages
        if (i_in_pages == -1) {
            miss++;

            // find free place in array pages and put there needed page
            for (int i = 0; i < n; i++) {
                if (pages[i].id == 0) {
                    i_in_pages = i;
                    pages[i].id = find_id;
                    pages[i].r_bit = 1;
                    break;
                }
            }

            // if there is no free place in array pages, find oldest page and replace it with needed
            // find page with min age = find least important page, that was needed a long time ago
            if (i_in_pages == -1) {
                int min_age = pages[0].age;
                int min_age_index = 0;

                for (int i = 1; i < n; i++) {
                    if (pages[i].age < min_age) {
                        min_age = pages[i].age;
                        min_age_index = i;
                    }
                }

                // replace page with min age with needed page
                i_in_pages = min_age_index;
                pages[i_in_pages].id = find_id;
                pages[i_in_pages].r_bit = 1;
                pages[i_in_pages].age = 0;
            }
        }

        // update ages
        for (int i = 0; i < n; i++) {
            pages[i].age >>= 1;
            pages[i].age += pages[i].r_bit * (1 << 30);
            pages[i].r_bit = 0;
        }
    }

    // print hit / miss ratio
    double ratio = (double)hit / (double)miss;
    printf("Hit / Miss = %d / %d = %lf", hit, miss, ratio);
    return 0;
}

/**
 * n = 10
 * Output:
 * Hit / Miss = 10 / 990 = 0.010101
 * 
 * n = 50
 * Output:
 * Hit / Miss = 52 / 948 = 0.054852
 * 
 * n = 100
 * Output:
 * Hit / Miss = 98 / 902 = 0.108647
 **/
