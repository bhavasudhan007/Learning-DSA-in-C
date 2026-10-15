
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ticket_no;
    char vehicle_registration_no[20];
    float gross_weight;
    float tare_weight;
} Ticket;

float net_weight(Ticket *t)
{
    return t->gross_weight - t->tare_weight;
}

void display_ticket(Ticket *t)
{
    printf("%d %s gross %.2f tare %.2f\n",
           t->ticket_no,
           t->vehicle_registration_no,
           t->gross_weight,
           t->tare_weight);

    printf("net %.2f\n", net_weight(t));
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 100000)
    {
        printf("INVALID COUNT\n");
        return 0;
    }

    Ticket *tickets = malloc(n * sizeof(Ticket));

    if (tickets == NULL)
        return 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %f %f",
              &tickets[i].ticket_no,
              tickets[i].vehicle_registration_no,
              &tickets[i].gross_weight,
              &tickets[i].tare_weight);
    }

    float total = 0.0;
    int max_index = 0;

    printf("WEIGHBRIDGE DAY BOOK\n");

    for (int i = 0; i < n; i++)
    {
        display_ticket(&tickets[i]);

        total += net_weight(&tickets[i]);

        if (net_weight(&tickets[i]) >
            net_weight(&tickets[max_index]))
        {
            max_index = i;
        }
    }

    printf("Tickets: %d\n", n);
    printf("Total net weight (kg): %.2f\n", total);

    printf("Heaviest net load: ticket %d %s\n",
           tickets[max_index].ticket_no,
           tickets[max_index].vehicle_registration_no);

    printf("%.2f\n", net_weight(&tickets[max_index]));

    free(tickets);

    return 0;
}
