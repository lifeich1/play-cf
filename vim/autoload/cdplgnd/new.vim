" vim: set sw=2 ts=2 et
"
" author: lifeich1

let s:cur_file = expand("<sfile>")

function! cdplgnd#new#new(code, name) abort
    let l:root_dir = fnamemodify(s:cur_file, ':h:h:h')
endfunction

function! cdplgnd#new#rename(code, name) abort
    "
endfunction


function! cdplgnd#new#newOrRename() abort
    let l:code = input("input problem code: ")
    if strlen(l:code) ==# 0
        echom "Require problem code!"
        return
    endif
    let l:name = input("input algo name(default 'main'): ", "main")
    let l:path = './src/' . l:code
    if isdirectory(l:path)
        cdplgnd#new#rename(l:code, l:name)
    else
        mkdir(l:path, "p")
        cdplgnd#new#new(l:code, l:name)
    endif
endfunction

function! cdplgnd#new#edit() abort
    let l:code = input("input problem code: ")
    let l:path = "./src/" . l:code 
    if !isdirectory(l:path)
        echom "File not found!"
        return
    endif
    cdplgnd#new#clear()
    edit glob(l:path . '/*.cpp')[0]
    botright vsplit l:path . "/type.h"
    botright split l:path . "/_io.cc"
    execute 1wincmd w
endfunction

function! cdplgnd#new#clear() abort
    bdelete %
endfunction
