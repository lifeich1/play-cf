" vim: set et
"
" author: lifeich1
" email: lifeich0@gmail.com 


function! cdplgnd#text#FindPrintPaths() abort
    let l:paths = cdplgnd#new#FindPath(cdplgnd#config#Current())
    return [l:paths[1], l:paths[2], l:paths[0]]
endfunction

function! cdplgnd#text#GetText() abort
    if ! cdplgnd#config#IsWorking() 
        return [""]
    endif

    let l:paths = cdplgnd#text#FindPrintPaths()
    let l:text = []
    for l:fil in l:paths
        let l:text += readfile(l:fil)
    endfor

    let l:output = []
    let l:flag = 0
    for l:line in l:text
        if match(l:line, '^ *\/\/-[') ==# 0
            let l:flag += 1
        endif
        if l:flag ==# 0
            call add(l:output, l:line)
        endif
        if match(l:line, '^ *\/\/-]') ==# 0
            let l:flag -= 1
        endif
    endfor

    return l:output
endfunction

function! cdplgnd#text#BrowseText() abort
    if cdplgnd#config#IsWorking()
        tabnew __Print__
        setlocal buftype=nofile
        call append(0, cdplgnd#text#GetText())
        setlocal readonly
        setlocal filetype=cpp
        setlocal nomodifiable
        normal gg
        nnoremap <script> <silent> <buffer> q :q<cr>:echo "quited"<cr>
        nnoremap <script> <silent> <buffer> h
                    \ :echo "'q' for quit, 'y' for yankall"<cr>
        let l:ykey = cdplgnd#config#YankKey()
        execute "nnoremap <script> <silent> <buffer> y " . l:ykey
    else
        echom "Currently NOT at ANY problem."
    endif
endfunction
