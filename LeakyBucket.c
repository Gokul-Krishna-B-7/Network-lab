#include <stdio.h>

int main() {
    int bucket_size, output_rate, incoming, outgoing, bucket = 0; 

    // Get bucket size from user
    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    // Get output rate from user
    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    // Get incoming packet size from user
    printf("Enter incoming packet size (0 to exit): ");
    scanf("%d", &incoming);

    // Process packets while incoming size is not zero
    while (incoming != 0) {
        // Check if incoming packet can be added to the bucket
        if (incoming <= (bucket_size - bucket)) {
            bucket += incoming;
            printf("Packet of size %d added. Bucket size: %d\n", incoming, bucket);
        } else {
            printf("Packet of size %d too large. Dropping packet.\n", incoming);
        }

        // Send out packets based on the output rate
        outgoing = (bucket < output_rate) ? bucket : output_rate;
        bucket -= outgoing;
        printf("Sent %d packets. Bucket size: %d\n", outgoing, bucket);

        // Get the next incoming packet size from user
        printf("Enter incoming packet size (0 to exit): ");
        scanf("%d", &incoming);
    }

    // Process remaining packets in the bucket
    while (bucket > 0) {
        outgoing = (bucket < output_rate) ? bucket : output_rate;
        bucket -= outgoing;
        printf("Sent %d packets. Bucket size: %d\n", outgoing, bucket);
    }

    return 0;
}
