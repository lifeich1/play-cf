" vim: set et foldmethod=marker
"
" author: lifeich1
" email: lifeich0@gmail.com 

let s:cur_file = expand("<sfile>")

" Relate to directory tree structure --- {{{
function! cdplgnd#new#GetDirectory(code) abort
    return "./src/" . a:code . "/"
endfunction

function! cdplgnd#new#GetPath(code, name) abort
    let l:path = cdplgnd#new#GetDirectory(a:code)
    return [l:path . "_io.cc", l:path . "type.h", l:path . a:name . ".cpp"]
endfunction

function!cdplgnd#new#FindPath(code) abort
    let l:paths = cdplgnd#new#GetPath(a:code, "*")
    let l:paths[-1] = glob(l:paths[-1], 0, 1)[0]
    return l:paths
endfunction
" }}}

function! cdplgnd#new#New(code, name) abort
" create new problem --- {{{
    " filenames and symbols ---- {{{
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

    let l:dst = cdplgnd#new#GetPath(a:code, a:name)
    " }}}

    " auto fill templates ---- {{{
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
        call writefile(l:output, l:dst[it])
    endfor
    " }}}

    call cdplgnd#new#Edit(a:code)
endfunction
" }}}

function! cdplgnd#new#Rename(code, name) abort
" rename problem's algo --- {{{
    " prepare symbols ---- {{{
    let l:t_path = cdplgnd#new#FindPath(a:code)
    let l:fio = l:t_path[0]
    let l:fty = l:t_path[1]
    let l:alg = l:t_path[2]

    let l:oname = fnamemodify(l:alg, ":t:r")
    let l:obase = "_" . a:code . "_" . l:oname
    let l:omacro = l:obase . "_H_INCLUDE"
    let l:oin = l:obase . "_in_t"
    let l:oout = l:obase . "_out_t"
    let l:ofunc = l:oname . "_" . a:code

    let l:tbase = "_" . a:code . "_" . a:name
    let l:tmacro = l:tbase . "_H_INCLUDE"
    let l:tin = l:tbase . "_in_t"
    let l:tout = l:tbase . "_out_t"
    let l:tfunc = a:name . "_" . a:code
    let l:_vars = ["base", "macro", "in", "out", "func"]
    " }}}

    " inflate rename symbols ---- {{{
    for l:file in [l:fio, l:fty, l:alg]
        let l:contents = readfile(l:file)
        let l:buf = []
        for line in l:contents
            let l:tmp = line
            for va in l:_vars
                let l:tmp = substitute(l:tmp, get(l:, "o".va),
                            \ get(l:, "t".va), "g")
            endfor
            call add(l:buf, l:tmp)
        endfor
        call writefile(l:buf, l:file)
    endfor
    " }}}

    let l:path = cdplgnd#new#GetDirectory(a:code)
    call rename(l:alg, l:path . a:name . ".cpp")

    call cdplgnd#new#Edit(a:code)
endfunction
" }}}


function! cdplgnd#new#NewOrRename() abort
" try create new files or rename old files --- {{{
    let l:code = input("input problem code: ")
    if match(l:code, '^\w\+$') !=# 0
        echom "Require problem code!"
        return
    endif
    let l:name = input("input algo name(default 'main'): ")
    if strlen(l:name) ==# 0
        let l:name = "main"
    endif
    if match(l:name, '^\h\w*$') !=# 0
        echo " "
        echom "Invalid name"
        return
    endif
    call cdplgnd#new#Clear()
    let l:path = './src/' . l:code
    if isdirectory(l:path)
        call cdplgnd#new#Rename(l:code, l:name)
    else
        call mkdir(l:path, "p")
        call cdplgnd#new#New(l:code, l:name)
    endif
endfunction
" }}}

function! cdplgnd#new#Edit(code) abort
" open editing windows --- {{{
    let l:path = cdplgnd#new#GetDirectory(a:code)
    if !isdirectory(l:path)
        echo " "
        echom "File not found!"
        return
    endif
    let l:layout = cdplgnd#config#EditLayout()
    let l:t_path = cdplgnd#new#FindPath(a:code)
    let l:fio = l:t_path[0]
    let l:fty = l:t_path[1]
    let l:alg = l:t_path[2]
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
    call cdplgnd#config#SetCurr(a:code)
endfunction
" }}}

function! cdplgnd#new#TryEdit() abort
" try edit --- {{{
    let l:code = input("input problem code: ")
    call cdplgnd#new#Clear()
    call cdplgnd#new#Edit(l:code)
endfunction
" }}}

function! cdplgnd#new#Clear() abort
" try close buffers --- {{{
    execute '%bdelete'
endfunction
" }}}
