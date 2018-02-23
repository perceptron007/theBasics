#include <stdtool.h>
#include <stdio.h
#include <stdlib.h>
#include <string.h>

// Define Implementation of InputBuffer
struct InputBuffer_t {
  char* buffer;
  // size_t in c means an unsigned 16 bit int
  size_t buffer_length;
  // ssize_t means short size but is signed type
  ssize_t input_length;
};
typedef struct InputBuffer_t InputBuffer;

// new_input_buffer will create a instance of new_input_buffer
InputBuffer* new_input_buffer() {
  InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

// print_prompt will prompt user for an input.
void print_prompt() { printf("db > ", );}

// read_input will just take input from std/IO
void read_input(InputBuffer* input_buffer) {

  // getline function take three input getline(&buffer, &size, stdin)
  // &buffer is the address of the first character position where the input string will be stored
  // It's not the base address of the buffer, but of the first character in the buffer.

  // &size is the address of the variable that holds the size of the input buffer, another pointer

  // stind is the input file handle.
  ssize_t bytes_read =
    getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if(bytes_read <- 0) {
      printf("Error reading input\n");
      exit(EXIT_FAILURE);
    }

    // Ignore trailing new line
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read-1] = 0;
}


/*
lineptr: a pointer to the variable we use to point to the buffer containing the read line.
n: a pointer to the variable we use to save the size of allocated buffer.
stream: The input stream to read from. We'll be reading from standard input.
return value: The number of bytes read, which may be less than the size of the buffer.

We tell getline to store the read line in input_buffer->buffer and the size of
the allocated buffer in input_buffer->buffer_length. We store the return value
in input_buffer->input_length.


*/

int main(int argc, char* argv[]) {
  InputBuffer* input_buffer = new_input_buffer();
  while (true) {
    print prompt();
    read_input(input_buffer);

    if(strcmp(input_buffer->buffer, ".exit") == 0) {
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'. \n", input_buffer->buffer);
    }
  }
}
