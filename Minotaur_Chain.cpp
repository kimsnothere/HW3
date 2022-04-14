#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <pthread.h>
#include <atomic>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
#include <mutex>

const int numPresents = 500000;
std::array<int,numPresents> giftBag;

std::atomic<int> bagIndex(0);
std::atomic<int> BagIndex(0);

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

class Node {
  public:
  int id;
  bool hasThanks;
  struct Node *next;
  struct Node *last;
};

Node *head = NULL;
Node *tail = NULL;

int main()
{
  srand(seed);

  // Set up bag of gifts
  for (int i = 0; i < numPresents; i++)
  {
    giftBag[i] = i;
  }
  shuffle(giftBag.begin(), giftBag.end(), std::default_random_engine(seed));


  printf("Done\n");

}

// I implemented this totally wrong, needed to alternate from 
void servant()
{
  int task = rand() % 3;

  if (task == 2) // Check if gift is in chain
  {
    int randomID = rand() % numPresents;
    Node *current = head;
    do {
      if (current->id == randomID)
      {
        printf("Guest ID %d is in the chain!", randomID);
        return;
      }
    } while(current->next != NULL);
    printf("Guest ID %d is not in the chain!", randomID);
  }

  else if (task == 1) // Write Thank You
  {
    int index;
    if(BagIndex < bagIndex)
    {
      index = BagIndex++;
    }
    else
    {
      return;
    }
    int guestID = giftBag[index];

    Node *current = head;
    do {
      if (current->id == guestID)
      {
        *(current->last) =  *(current->next);
      }
    } while(current->next != NULL);
  }

  else  // Put the item in list
  {
    int index = bagIndex++;
    int guestID = giftBag[index];

  }
}
