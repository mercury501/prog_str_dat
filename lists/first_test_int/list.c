#include "list.h"

struct node
{
    item value;
    struct node *next;
} node;

list newList(void)
{
    return NULL;
}

int emptyList(list l)
{
    return l == NULL;
}

list tailList(list l)
{
    list temp;
    if (l != NULL)
        temp = l->next;
    else
        temp = NULL;
    return temp;
}

list consList(item val, list l)
{
    struct node *nuovo;
    nuovo = xmalloc(sizeof(struct node));
    if (nuovo != NULL)
    {
        nuovo->value = val;
        nuovo->next = l;
        l = nuovo;
    }
    return l;
}

item getFirst(list l)
{
    item e;
    if (l != NULL)
        e = l->value;
    else
        e = NULLITEM;
    return e;
}

int sizeList(list l)
{
    int n = 0;
    while (!emptyList(l))
    {
        n++;
        l = tailList(l);
    }
    return n;
}

int posItem(list l, item val)
{
    if (emptyList(l))
        return -1;
    if (eq(getFirst(l), val))
        return 0;
    else
    {
        int ris = posItem(tailList(l), val);
        if (ris == -1)
            return -1;
        else
            return 1 + ris;
    }
}

item getItem(list l, int pos)
{
    item e;
    int i = 0;
    // prima scorriamo la lista fino alla posizione pos … se esiste
    while (i < pos && !emptyList(l))
    {
        i++;
        l = tailList(l);
    }

    if (!emptyList(l))   // se la lista ha almeno pos+1 elementi
        e = getFirst(l); // elemento di posizione pos
    else
        e = NULLITEM;

    return e;
}

list reverseList(list l)
{
    list rev;
    item val;

    rev = newList();

    while (!emptyList(l))
    {
        val = getFirst(l);
        rev = consList(val, rev);
        l = tailList(l);
    }

    return rev;
}

void outputList(list l)
{
    int i = 0;
    item val;

    while (!emptyList(l))
    {
        val = getFirst(l);
        printf("Elemento di posizione %d: ", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

list inputList(int n)
{
    item val;
    list l = newList();

    for (int i = 0; i < n; i++)
    {
        printf("Elemento di posizione %d: ", i);
        input_item(&val);
        l = consList(val, l);
    }
    // alla fine del ciclo l contiene gli elementi della lista al contrario
    return reverseList(l);
}

list insertList(list l, int pos, item val)
{
    if (pos == 0) // inserimento in posizione 0
        return consList(val, l);

    /* se non dobbiamo inserire in posizione 0 scorriamo la lista 
fino alla posizione precedente a quella in cui inserire il nuovo nodo */

    int i = 0;
    list prec = l;
    while (i < pos - 1 && prec != NULL)
    {
        prec = prec->next;
        i++;
    }

    if (prec == NULL) // la lista di input ha meno di pos elementi
        return l;

    /* se prec != NULL prec punta all’elemento di posizione pos-1 ed 
è possibile inserire il nuovo elemento in posizione pos */

    list l1 = consList(val, prec->next);
    prec->next = l1;

    return l; /* se abbiamo inserito in posizione > 0 l punta ancora
                               al primo elemento */
}

list removeList(list l, int pos)
{
    list l1; // puntatore al nodo da eliminare

    if (pos == 0 && l != NULL)
    { // eliminazione in posizione 0
        l1 = l;
        l = tailList(l);
        free(l1);
    }
    else
    {

        /* se non dobbiamo cancellare in posizione 0 scorriamo la lista 
fino alla posizione precedente a quella del nodo da eliminare */

        int i = 0;
        list prec = l;
        while (i < pos - 1 && prec != NULL)
        {
            prec = prec->next;
            i++;
        }
        /* alla fine del ciclo, se prec != NULL allora prec->next punta al nodo da 
   eliminare. Se prec->next != NULL allora il nodo si può eliminare */

        if (prec != NULL && prec->next != NULL)
        { // short-circuit evaluation
            l1 = prec->next;
            prec->next = l1->next;
            free(l1);
        }
    }

    return l;
}
