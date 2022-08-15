# Huffman_Coding

This project is a C++ compression and decompression program based on Huffman Coding.

Introduction:

This project is to design compression and decompression programs based on Huffman Coding. The idea of Huffman Coding is to minimize the weighted expected length of the code by means of assigning shorter codes to frequently-used characters and longer codes to seldom-used code. This program can compress and decompress text file consisting of 128 ASCII characters.

Compression:

1. Count and store the frequencies of different characters.

2. Build Priority Queue and then Huffman Tree.

3. Calculate Huffman Encode Table.

4. Encode the file, store Huffman Encode Table and encode to the desired file.

Decompression:

1. Open file, recreate Huffman Tree based on Huffman Encode Table.

2. Decode the file based on the tree and store it to the desired file.
