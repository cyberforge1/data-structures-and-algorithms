source venv/bin/activate

pip install pandas

python main.py


# Running main.c

gcc -DUSE_BINARY_SEARCH main.c algorithms/binary_search/binary_search.c -o search_program


gcc main.c algorithms/linear_search/linear_search.c -o search_program
./search_program



gcc dfs.c -o dfs
./dfs