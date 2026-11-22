#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#define isnum(c) (((c) >= '0') && ((c) <= '9'))
#define STARTSIZE 64
#define NOTNUM 0
#define INNUM 1

int
main(void)
{
    std::string s;
    size_t nsize;
    int bufnum; 
    int status;
    int nnums;
    int *tmp;
    size_t i;

    if (!std::getline(std::cin, s, '\n')) {
        std::cout << "input error\n";
        return 1;
    }

    nsize = STARTSIZE;
    int *nums = (int *)malloc(sizeof(int)*nsize);
    if (!nums) {
        std::cout << "malloc error\n";
        return 1;
    }

    status = NOTNUM;
    bufnum = 0;
    nnums  = 0;
    i = 0;
    for (; i<s.size(); ++i) {
        if (isnum(s[i])) {
            bufnum = bufnum*10 + s[i] - '0';
            status = INNUM;
        } else {
            if (status == INNUM) {
                if ((size_t)(nnums+1) > nsize) { /* +1 for trailing number to avoid realloc */
                    nsize*=2;
                    tmp = NULL;
                    tmp = (int *)realloc(nums, sizeof(int)*nsize);
                    if (!tmp) {
                        free(nums);
                        std::cout << "realloc error\n";
                        return 1;
                    }
                    nums = tmp;
                    tmp = NULL;
                }
                nums[nnums++] = bufnum;
                bufnum = 0;
            }
            status = NOTNUM;
            continue;
        }
    }
    if (status == INNUM) {
        nums[nnums++] = bufnum;
    }
    i = 0;
    for (; i<(size_t)nnums; ++i) {
        std::printf("%d ", nums[i]);
    }
    std::putchar('\n');
    free(nums);
    return 0;
}
