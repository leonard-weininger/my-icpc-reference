set ts=8 sw=4 nu rnu ai si mouse=a
sy on
im än <esc>
im ön std::
im {<cr> {<cr>}<esc>O
nm <f5> :!clear && ./%:r <cr>
nm <f9> :w \| !clear && g++ % -std=gnu++20 -Wall -Wshadow -O2 -o %:r <cr>
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6

Hash: 767a21
