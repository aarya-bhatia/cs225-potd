// #include "Memory.h"
// #include <iostream>
// #include <iomanip>
// #include "Node.h"
// #include <vector>
// #include <utility>

// using namespace std;

// /**
// Frees the given memory address. Returns if the free was successful or not
// Be sure to merge adjacent free blocks when possible
// */
// bool Memory::free(unsigned address) {
//     std::cout << "Freeing chunk at address " << address << std::endl;
//     Node* current = head;
//     while (current != NULL) {
//         if (current->address == address) {
//             // Your code there
//             current->inUse = false;

//             // See if we can merge
//             Node* prev = current->previous;
//             Node* next = current->next;

//             if (prev != NULL && !prev->inUse) {
//                 // Your code there
//                 std::cout << "Merging " << current->address << " and " << prev->address << std::endl;
//                 prev->next = next;
//                 if(next != NULL) {
//                     next->previous = prev;
//                 }
//             }

//             if (next != NULL && !next->inUse) {
//                 // Your code there
//                 std::cout << "Merging " << current->address << " and " << next->address << std::endl;
//                 next->previous = prev;

//                 if(current == head) {
//                     current = next;
//                 }

//                 if(prev != NULL) {
//                     prev->next = next;
//                 }
//             }

//             // Node *temp = current->next;
//             // delete current;
//             // current = temp;

//             return true;
//         }

//         current = current->next;

//     }

//     return false;
// }


// /**
// Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
// chunk of free memory above.

// Note: We do not care about the order of the allocated memory chunks
// */
// void Memory::defragment() {
//     Node* current = head;
//     while (current != NULL) {

//         if (current->inUse) {
//             // Do nothing
//         } else {
//             // TODO: Find the next chunk of allocated memory and shift it down to current's address
//             // We recommend using the helper function `findNextAllocatedMemoryChunk` and `getSize`
//             // Your code here

//             Node * chunk = findNextAllocatedMemoryChunk(current);

//             if(chunk != NULL) {
//                 size_t size = getSize(chunk);
//                 free(chunk->address);
//                 std::cout << "Allocating " << size << " bytes..." << std::endl;
//                 allocate(size);
//             }
//         }

//         current = current->next;
//     }

//     // TODO: Finally merge all of the free blocks of memory together
//     Node *newNode = new Node(0, true);
//     newNode->next = current;
//     newNode->previous = NULL;
//     head = newNode;
// }

#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

// No memory deallocation

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address)
{
    Node *current = head;

    while (current != NULL)
    {
        if (current->address == address)
        {
            current->inUse = false;

            // See if we can merge
            Node *prev = current->previous;
            Node *next = current->next;
            if (prev != NULL && !prev->inUse)
            {
                prev->next = next;
                next->previous = prev;
                free(prev->address);
            }

            if (next != NULL && !next->inUse)
            {
                current->next = next->next;
                next->previous = current->previous;
                free(next->address);
            }

            return true;
        }
        current = current->next;
    }

    return false;
}

/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.
Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment()
{
    Node *current = head;
    while (current != NULL)
    {

        if (!current->inUse)
        {
            // Find the next chunk of allocated memory and shift it down to current's address

            Node *next_used = findNextAllocatedMemoryChunk(current);
            if (next_used == NULL)
                return;
            if (current == head)
                head = next_used;
            int size = getSize(next_used);

            Node *prev = current->previous;

            current->previous = next_used;
            if (current->next == next_used)
            {
                current->next = next_used->next;
                if (current->next != NULL)
                {
                    current->next->previous = current;
                }
            }

            next_used->next = current;
            next_used->previous = prev;
            if (next_used->previous != NULL)
            {
                next_used->previous->next = next_used;
            }

            next_used->address = current->address;
            current->address += size;

            free(current->address);
            current = current->previous;
        }

        current = current->next;
    }
}