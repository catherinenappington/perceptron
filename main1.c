#include <stdio.h>
#include <stdlib.h>

#define threshold 0.5
#define learning_rate 0.1

double dot_product(int x[], double y[]);

int main()
{
    int i, j, k, network, error, error_count = 1;
    double sum;
    double weights[] = {0, 0, 0};
    int training_set[4][3] = { {1, 0, 0},
                          {1, 0, 1},
                          {1, 1, 0},
                          {1, 1, 1}
                          };
    int desired_output[] = {1, 1, 1, 0};

    for(i = 0;error_count != 0; i++)
    {
        printf(" Iteration:  %d  ************************************************************\n", i);
        error_count = 0;
        for(j = 0; j < 4; j++)
        {
            sum = dot_product(training_set[j], weights);

            network = sum > threshold ? 1 : 0;

            error = desired_output[j] - network;

            if(error != 0)
                error_count++;

            for(k = 0; k < 3; k++)
            {
                weights[k] += learning_rate * error * training_set[j][k];
            }
            printf("%.1f %.1f %.1f\t Correction = %.5f\n", weights[0], weights[1], weights[2], error * learning_rate);
        }
    }
    return 0;
}

double dot_product(int sensor_values[], double initial_weights[])
{
    return (sensor_values[0] * initial_weights[0] + sensor_values[1]
            * initial_weights[1] + sensor_values[2] * initial_weights[2]);
}
