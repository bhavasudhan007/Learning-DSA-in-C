
#include <stdio.h>

typedef union
{
    float temperature;
    char door_state;
    long pulses;
} Value;

typedef struct
{
    int sensor_id;
    char kind;
    Value value;
} Reading;

typedef struct
{
    int sensor_id;
    char kind;
    float temperature;
    char door_state;
    long pulses;
} FullReading;

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 1000)
    {
        printf("INVALID COUNT\n");
        return 0;
    }

    Reading readings[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &readings[i].sensor_id,
                        &readings[i].kind);

        switch (readings[i].kind)
        {
            case 'T':
                scanf("%f", &readings[i].value.temperature);
                break;

            case 'D':
                scanf(" %c", &readings[i].value.door_state);
                break;

            case 'P':
                scanf("%ld", &readings[i].value.pulses);
                break;

            default:
                printf("INVALID KIND\n");
                return 0;
        }
    }

    printf("SENSOR REPORT\n");

    for (int i = 0; i < n; i++)
    {
        switch (readings[i].kind)
        {
            case 'T':
                printf("Sensor %d temperature %.2f C\n",
                       readings[i].sensor_id,
                       readings[i].value.temperature);
                break;

            case 'D':
                if (readings[i].value.door_state == 'O')
                    printf("Sensor %d door OPEN\n",
                           readings[i].sensor_id);
                else
                    printf("Sensor %d door CLOSED\n",
                           readings[i].sensor_id);
                break;

            case 'P':
                printf("Sensor %d pulses %ld\n",
                       readings[i].sensor_id,
                       readings[i].value.pulses);
                break;
        }
    }

    printf("sizeof(union Value): %zu\n", sizeof(Value));
    printf("sizeof(Reading) with union: %zu\n", sizeof(Reading));
    printf("sizeof(Reading) with all fields: %zu\n",
           sizeof(FullReading));

    printf("Bytes saved per record: %zu\n",
           sizeof(FullReading) - sizeof(Reading));

    return 0;
}
