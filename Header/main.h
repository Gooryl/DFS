//
// Created by Юрий Быковцев on 12.07.2018.
//

#ifndef DFS_MAIN_H
#define DFS_MAIN_H

#define MAX_DIGITS 256
#define TRUE 1
#define FALSE 0

unsigned char input_check(unsigned char*, unsigned char*);
void adjacency_matrix_builder(unsigned char, unsigned char*);
void DFS (unsigned char, unsigned char*, unsigned char*, unsigned char);

#endif //DFS_MAIN_H
