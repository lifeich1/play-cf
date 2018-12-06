" vim: set sw=2 ts=2 et
"
" author: lifeich1

let s:cur_file = expand("<sfile>")

function! cdplgnd#new#New(code, name) abort
    let l:root_dir = fnamemodify(s:cur_file, ':h:h:h')
    let l:template = l:root_dir . "/templates/"
    let l:qio = l:template . cdplgnd#config#TemplateIOFile()
    let l:qyp = l:template . cdplgnd#config#TemplateTypeHeader()
    let l:qal = l:template . cdplgnd#config#TemplateAlgoFile()
    let l:ins = [l:qio, l:qyp, l:qal]

    let l:tbase = "_" . a:code . "_" . a:name
    let l:tmacro = l:tbase . "_H_INCLUDE"
    let l:tin = l:tbase . "_in_t"
    let l:tout = l:tbase . "_out_t"
    let l:tfunc = a:name . "_" . a:code
    let l:tvars = ["tbase", "tmacro", "tin", "tout", "tfunc"]

    let l:dst = "./src/" . a:code . "/"
    let l:dfs = ["_io.cc", "type.h", a:name . ".cpp"]

    for it in range(3)
        let l:contents = readfile(l:ins[it])
        let l:output = []
        for line in l:contents
            let l:tmp = line
            for va in l:tvars
                let l:tmp = substitute(l:tmp, "$" . va, get(l:, va), "g")
            endfor
            call add(l:output, l:tmp)
        endfor
        call writefile(l:output, l:dst . l:dfs[it])
    endfor

    call cdplgnd#new#Edit(a:code)
endfunction

function! cdplgnd#new#Rename(code, name) abort
    " rename TODO

    call cdplgnd#new#Edit(a:code)
endfunction


function! cdplgnd#new#NewOrRename() abort
    let l:code = input("input problem code: ")
    if strlen(l:code) ==# 0
        echom "Require problem code!"
        return
    endif
    let l:name = input("input algo name(default 'main'): ")
    if strlen(l:name) ==# 0
        let l:name = "main"
    endif
    if match(l:name, '^\a')
        echo " "
        echom "Error! Name must start with alphabetic"
        return
    endif
    let l:path = './src/' . l:code
    if isdirectory(l:path)
        call cdplgnd#new#Rename(l:code, l:name)
    else
        call mkdir(l:path, "p")
        call cdplgnd#new#New(l:code, l:name)
    endif
endfunction

function! cdplgnd#new#Edit(code) abort
    let l:path = "./src/" . a:code 
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

function! cdplgnd#new#TryEdit() abort
    let l:code = input("input problem code: ")
    call cdplgnd#new#Edit(l:code)
endfunction

function! cdplgnd#new#Clear() abort
    execute '%bdelete'
endfunction
