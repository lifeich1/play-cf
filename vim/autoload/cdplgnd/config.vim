" vim: set et
"
" author: lifeich1
" email: lifeich0@gmail.com 

function! cdplgnd#config#EditLayout()
    return get(g:, "CodePlayground_EditLayout", "split12")
endfunction

function! cdplgnd#config#TemplateIOFile()
    return get(g:, "CodePlayground_TemplateIOFile", "codeplay_2_io.cc")
endfunction

function! cdplgnd#config#TemplateTypeHeader()
    return get(g:, "CodePlayground_TemplateTypeHeader", "codeplay_1type.h")
endfunction

function! cdplgnd#config#TemplateAlgoFile()
    return get(g:, "CodePlayground_TemplateAlgoFile", "codeplay_3algo.cpp")
endfunction

let s:gcodevar = "#"

function! cdplgnd#config#Current()
    return s:gcodevar
endfunction

function! cdplgnd#config#SetCurr(code)
    let s:gcodevar = a:code
endfunction

function! cdplgnd#config#IsWorking()
    return cdplgnd#config#Current() !=# "#"
endfunction
