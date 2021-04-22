#include <stdio.h>
#include "utile.h"
#include "queue.h"
#include "item.h"

queue load_points_file(char *fname){
    int i, j;
    float tempa, tempo;
    char buff[10];
    queue new_queue = newQueue();
    FILE *fp = open_file_read(fname);

    for (i = 0;feof(fp) == 0; i++)  //conta le linee del file
        fscanf(fp, "%s", buff);

    rewind(fp);

    for(j = 0; j < i / 2; j ++){    //legge i valori dei punti
        fscanf(fp, "%s\n", buff);
		tempa = atof(buff);
        fscanf(fp, "%s\n", buff);
		tempo = atof(buff);
        enqueue(creaItem(tempa, tempo), new_queue);
    }

    fclose(fp);
    return new_queue;
}

queue read_points(){
    float tempa = 0, tempo;
    queue new_queue = newQueue();

    printf("Inserire coppie di punti, terminati con un -42\n");

    while (1){
        scanf("%f", &tempa);
        if (tempa == -42)
            break;
        scanf("%f", &tempo);

        enqueue(creaItem(tempa, tempo), new_queue);
    }

    return new_queue;
}

void dividi_quadranti(queue q, queue q1, queue q2, queue q3, queue q4){

    int i, dim = dimQueue(q);
    item temp;
    for(i=0; i < dim; i++) {    
        temp = dequeue(q);
        if (item_x(temp) > 0) {
            if (item_y(temp) > 0) {
                enqueue(temp, q1);
            }
            else {
                enqueue(temp, q4);
            }
        }
        else {
            if (item_y(temp) > 0){
                enqueue(temp, q2);
            }
            else {
                enqueue(temp, q3);
            }

        }
    }

    free(q);
}

void simmetrici(queue q1, queue q2, queue simm){
    int i, j;
    int dim1 = dimQueue(q1);
    int dim2 = dimQueue(q2);
    item it1, it2;
    queue temp1 = cloneQueue(q1);   //cloniamo la coda per non distruggere l'originale
    queue temp2;

    for (i = 0; i < dim1; i++){
        it1 = dequeue(temp1);
        temp2 = cloneQueue(q2); //ricloniamo la seconda distrutta ogni volta nel for annidato
        for( j = 0; j < dim2; j++){
            it2 = dequeue(temp2);   //estraiamo un item
            if ((item_x(it1) + item_x(it2) + item_y(it1) + item_y(it2)) == 0){
                    enqueue(it1, simm);
                    enqueue(it2, simm);
            }
        }
    }
    
    free(temp1);    //liberiamo le code vuote
    free(temp2);

}

float spezzata(queue q){

    queue temp = cloneQueue(q); //cloniamo la coda per non distruggere l'originale
    int i, dim = dimQueue(q);
    float result = 0;
    
    item it1, it2;
    it1 = dequeue(temp);    //inizializziamo il ciclo estraendo il primo item

    for (i = 0; i < (dim - 1); i++){
        it2 = dequeue(temp);    //estraiamo il secondo item
        result += distanza(it1, it2);   //distanza
        it1 = it2;  //il primo item diventa il secondo per il prossimo ciclo

    }

    free(temp); //liberiamo la coda vuota temp
    return result;


}

int main(int argc, char *argv[]){

    queue coda;

    if (argc > 1)
        coda = load_points_file(argv[1]);
    else    
        coda = read_points();

    print_queue(coda);

    queue q1 = newQueue();
    queue q2 = newQueue();
    queue q3 = newQueue();
    queue q4 = newQueue();

    dividi_quadranti(coda, q1, q2, q3, q4);

    printf("Primo quadrante:\n");
    print_queue(q1);
    printf("Secondo quadrante:\n");
    print_queue(q2);
    printf("Terzo quadrante:\n");
    print_queue(q3);
    printf("Quarto quadrante:\n");
    print_queue(q4);

    queue simm13 = newQueue();
    queue simm24 = newQueue();

    simmetrici(q1, q3, simm13);
    simmetrici(q2, q4, simm24);

    printf("Simmetrici primo terzo:\n");
    print_queue(simm13);
    printf("Simmetrici secondo quarto:\n");
    print_queue(simm24);

    printf("La distanza della spezzata sul primo quadrante è:   %f\n", spezzata(q1));
    queue concatenation = catQueue(q1, q2);
    printf("Concatenazione tra primo e secondo quadrante: \n");
    print_queue(concatenation);
    
    return 0;

}