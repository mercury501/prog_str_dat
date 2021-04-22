#include "queue.h"

struct node {
     item value;
     struct node *next;
};

struct c_queue {
     struct node *head,*tail;
     int numel;
};

queue newQueue(void)
{
     struct c_queue *q;
     q = malloc (sizeof(struct c_queue));
     if (q == NULL) 
	return NULL;

     q->numel = 0;
     q->head = NULL;
     q->tail = NULL;
     return q;
} 

int emptyQueue(queue q)
{
     if (q==NULL)
            return -1;
     return q->numel == 0;
}

int enqueue(item val, queue q)
{
    if (q==NULL)
            return -1;

    struct node *nuovo;
    nuovo = malloc (sizeof(struct node));
    if (nuovo == NULL) return 0;

    nuovo->value = val;
    nuovo->next= NULL;

    if(q->head==NULL)
         q->head = nuovo;         //  caso coda vuota
    else 
         q->tail->next= nuovo;  //  caso coda non vuota

    q->tail = nuovo;                // tail punta al nuovo nodo
    (q->numel)++;                   // incrementare il numero di elementi
    return 1;     
}

item dequeue(queue q)
{
      if (q==NULL) return NULLITEM;

      if (q->numel == 0) return NULLITEM;    //  coda vuota

      item result = q->head->value;   //  item da restituire

      struct node *temp = q->head;   //  nodo da rimuovere
     
      q->head = q->head->next;        // q->head avanza
      free(temp);                 // liberiamo memoria nodo da rimuovere

      if(q->head==NULL)   // se la coda conteneva un solo elemento
             q->tail=NULL; 
      
      (q->numel)--;

      return result;
}

queue cloneQueueHeader(queue q){   //deprecated
     queue new = newQueue();
     new->head = q->head;
     new->tail = q ->tail;
     new->numel = q->numel;

     return new;
}

queue cloneQueue(queue q){
     int i;
     queue temp = cloneQueueHeader(q);
     queue new = newQueue();

     for (i = 0; i < dimQueue(q); i++){
          enqueue(temp->head->value, new);
          temp->head = temp->head->next;
     }
     return new;
}


void print_queue(queue q){
     struct node *temp = q->head;
     int i;
     for (i = 0; i < q->numel; i++){
          printf("Elemento n. %d:  ", i);
          output_item(temp->value);
          temp = temp->next;

    }
}

int dimQueue(queue q){

     return q->numel;

}

queue catQueue(queue q1, queue q2){
     int i;
     queue new = cloneQueue(q1);
     queue temp = cloneQueue(q2);
     
     for (i = 0; i < dimQueue(q2); i++)
          enqueue(dequeue(temp), new);

     free(temp);
     return new;

}