#include "list.h"

struct c_list
{
    struct node *first;
    int size;
};

struct node
{
    item value;
    struct node *next;
};

static struct node* removeNode(struct node* l, int pos)
{     
    struct node* l1;    // puntatore al nodo da eliminare

    if(pos == 0 && l != NULL) {       // eliminazione in posizione 0
        l1 = l;
        l = l->next;
        free(l1);
    }
else {
        // scorriamo la lista fino alla posizione precedente a quella 
        // del nodo da eliminare
        int i = 0;
        struct node* prec = l;         
        while (i < pos-1 && prec!= NULL) {   
            prec = prec->next;
            i++;
        }
/* alla fine del ciclo, se prec != NULL allora prec->next punta al nodo da 
   eliminare. Se prec->next != NULL allora il nodo si può eliminare */
        if(prec != NULL && prec->next != NULL) { // short-circuit evaluation
            l1 = prec->next;
            prec->next = l1->next;
            free(l1); 
        }
    }
    return l; 
}

static struct node *insertNode(struct node *l, int pos, item val)
{
    struct node *new, *prec = l;
    int i;
    new = malloc(sizeof(struct node));
    if (!new)
        return NULL;
    new->value = val;
    if (pos == 0)
    { // inserimento in testa
        new->next = l;
        return new;
    }
    while (i < pos - 1 && prec != NULL)
    { // scorro la lista fino ad arrivare a pos
        prec = prec->next;
        i++;
    }
    if (prec == NULL)
    { // la lista di input ha meno di pos elementi
        free(new);
        return NULL;
    }
    new->next = prec->next;
    prec->next = new; // aggiungo in posizione pos
    return l;
}

list newList(void)
{
    struct c_list *l;
    l = xmalloc(sizeof(struct c_list));
    if (l != NULL)
    {
        l->first = NULL;
        l->size = 0;
    }
    return l;
    // il programma client dovrà controllare che il risultato non sia NULL
}

int emptyList(list l){
    if (l->size > 0)
        return 0;

    return 1;
}

list tailList(list l){
    int i, dim = l->size;
    list list_temp = newList();
    struct node n_temp;

    list_temp->size = dim - 1;
    list_temp->first = l->first->next;

    return list_temp;
}

list consList(item val, list l){        
    struct node *n_temp;
    n_temp = insertNode(l->first, 0, val);

    l->first = n_temp;
    l->size += 1;
    return l;
}

int insertList(list l, int pos, item val)
{
    struct node *tmp = insertNode(l->first, pos, val);
    if (tmp == NULL)
        return 0;
    l->first = tmp;
    l->size++;
    return 1;
}



int removeList (list l, int pos)
{     
    if (l->first==NULL || l->size==0)   return 0;   // non ci sono elementi
    l->first = removeNode(l->first,pos);
    l->size--;
    return 1;
}

item getFirst (list l){
    if (l->size == 0)
        return NULL;

    return l->first->value;
}

int sizeList(list l){

    return l->size;
}

int posItem(list l, item val){
    int i;
    struct node *temp = l->first;
    if (emptyList(l))
        return -1;


    for (i = 0; i < sizeList(l); i++)
        if (temp->value == val){
            return i;
        }

    return -1;
}

item getItem (list l, int pos){
    int i;
    struct node *temp;
    temp = l->first;

    for (i = 0; i < pos; i++)
        temp = temp->next;
    
    return temp->value;
}

list reverseList (list l){
    int i;
    list new = newList();
    new->size = 0;

    struct node * temp_node;
    temp_node = l->first;

    for (i = 0; i < sizeList(l); i++){
        new = insertNode(temp_node, 0, temp_node->value);
        
        temp_node = temp_node->next;
        new->size += 1;
    }

    return new;
}

void outputList (list l){
    int i = 0;
    item val;

    while (!emptyList(l)){
        val = getFirst(l);
        printf("Elemento di posizione %d: ", i);
        output_item(val);
        printf("\n");
        
        l = tailList(l);
        i +=1;
    }
}

list inputList (int n){
    item val;
    
    list new = newList();
        for (int i = 0; i < n; i++)
    {
        printf("Elemento di posizione %d: ", i);
        input_item(&val);
        new = consList(val, new);
    }
    // alla fine del ciclo l contiene gli elementi della lista al contrario
    return reverseList(new);


}