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
    let l:layout = cdplgnd#config#EditLayout()
    let l:fio = l:path . "/_io.cc"
    let l:fty = l:path . "/type.h"
    let l:alg = glob(l:path . '/*.cpp', 0, 1)[0]
    if l:layout ==? "tabs"
        execute "tabedit " . l:fio
        execute "tabonly"
        execute "tabedit " . l:fty
        execute "tabedit " . l:alg
        execute "1tabnext"
    else " 'split12'
        execute "edit " . l:fio
        execute "topleft split " . l:fty 
        execute "topleft vsplit " . l:alg
        execute "1wincmd w"
    endif
endfunction

function! cdplgnd#new#Clear() abort
    execute '%bdelete'
endfunction
