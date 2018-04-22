# NOISY CHANNELS

## Stop-and-Wait ARQ
### In Stop-and-Wait ARQ, we use sequence numbers to number the frames. The sequence numbers are based on modulo-2 arithmetic.
### The acknowledgment number always announces in modulo-2 arithmetic the sequence number of the next frame expected.

## Go-Back-N ARQ
### In the Go-Back-N Protocol, the sequence numbers are modulo 2m, where m is the size of the sequence number field in bits.
### The send window can slide one or more slots when a valid acknowledgment arrives.
### In Go-Back-N ARQ, the size of the send window must be less than 2m; the size of the receiver window is always 1.

### Stop-and-Wait ARQ is a special case of Go-Back-N ARQ in which the size of the send window is 1.

## Selective Repeat ARQ
### In Selective Repeat ARQ, the size of the send window and receiver window must be less than or equal to half of 2m.
### Sender sends duplicate frame after receiving negative acknowledgement.
