" vim: set sw=2 ts=2 et
"
" author: lifeich1

let s:cur_file = expand("<sfile>")

function! cdplgnd#new#New(code, name) abort
    let l:root_dir = fnamemodify(s:cur_file, ':h:h:h')
endfunction

function! cdplgnd#new#Rename(code, name) abort
    "
endfunction


function! cdplgnd#new#NewOrRename() abort
    let l:code = input("input problem code: ")
    if strlen(l:code) ==# 0
        echom "Require problem code!"
        return
    endif
    let l:name = input("input algo name(default 'main'): ", "main")
    let l:path = './src/' . l:code
    if isdirectory(l:path)
        call cdplgnd#new#Rename(l:code, l:name)
    else
        call mkdir(l:path, "p")
        call cdplgnd#new#New(l:code, l:name)
    endif
endfunction

function! cdplgnd#new#Edit() abort
    let l:code = input("input problem code: ")
    let l:path = "./src/" . l:code 
    if !isdirectory(l:path)
        echom "File not found!"
        return
    endif
    call cdplgnd#new#Clear()
    execute "edit " . glob(l:path . '/*.cpp', 0, 1)[0]
    execute "botright vsplit " . l:path . "/type.h"
    execute "botright split " . l:path . "/_io.cc"
    execute "1wincmd w"
endfunction

function! cdplgnd#new#Clear() abort
    bdelete %
endfunction
