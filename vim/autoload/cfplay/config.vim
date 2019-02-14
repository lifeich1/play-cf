" vim: set et
"
" author: lifeich1
" email: lifeich0@gmail.com 

function! cfplay#config#YankKey()
    return get(g:, "Cfplay_YankKey", ":%y +<cr>")
endfunction

function! cfplay#config#EditLayout()
    return get(g:, "Cfplay_EditLayout", "split12")
endfunction

function! cfplay#config#TemplateIOFile()
    return get(g:, "Cfplay_TemplateIOFile", "codeplay_2_io.cc")
endfunction

function! cfplay#config#TemplateTypeHeader()
    return get(g:, "Cfplay_TemplateTypeHeader", "codeplay_1type.h")
endfunction

function! cfplay#config#TemplateAlgoFile()
    return get(g:, "Cfplay_TemplateAlgoFile", "codeplay_3algo.cpp")
endfunction

function! cfplay#config#TemplateMakefile()
    return get(g:, "Cfplay_TemplateMakefile", "codeplay_0makefile.mk")
endfunction

let s:gcodevar = "#"
let s:code_mk = "build/__code__.mk"

function! cfplay#config#Current()
    return s:gcodevar
endfunction

function! cfplay#config#SetCurr(code)
    let s:gcodevar = a:code
    let l:bdir = fnamemodify(s:code_mk, ":h")
    if !isdirectory(l:bdir)
        call mkdir(l:bdir, "p")
    endif
    call writefile(["CODE := " . a:code, ""], s:code_mk)
endfunction

function! cfplay#config#IsWorking()
    return cfplay#config#Current() !=# "#"
endfunction
