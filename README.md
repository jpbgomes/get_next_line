# TODO
- Norm
- Header
- Tester
- If can send Makefile

# CONCEPTS / TESTS
- Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?
- Exhibits undefined behavior if the file associated with the file descriptor is modified after the last call, while read() has not yet reached the end of the file.
- Exhibits undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

# FORBIDDEN
- lseek()
- Global variables