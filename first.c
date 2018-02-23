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

// InputBuffer is a small wrapper around the state we need to store
struct InputBuffer_t {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
};
// Ask Mamiji what does this line do ?
typedef struct InputBuffer_t InputBuffer;

// new_input_buffer will create a instance of new_input_buffer
InputBuffer* new_input_buffer() {
  InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer->length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

// print_prompt will prompt user for an input.
void print_prompt() { printf("db > ", );}

// getline() function will ask for a user input
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/*
lineptr: a pointer to the variable we use to point to the buffer containing the read line.
n: a pointer to the variable we use to save the size of allocated buffer.
stream: The input stream to read from. We'll be reading from standard input.
return value: The number of bytes read, which may be less than the size of the buffer.

We tell getline to store the read line in input_buffer->buffer and the size of
the allocated buffer in input_buffer->buffer_length. We store the return value
in input_buffer->input_length.

*/
