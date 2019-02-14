" vim: set et
"
" author: lifeich1
" email: lifeich0@gmail.com 


function! cfplay#text#FindPrintPaths() abort
    let l:paths = cfplay#new#FindPath(cfplay#config#Current())
    return [l:paths[1], l:paths[2], l:paths[0]]
endfunction

function! cfplay#text#GetText() abort
    if ! cfplay#config#IsWorking() 
        return [""]
    endif

    let l:paths = cfplay#text#FindPrintPaths()
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

function! cfplay#text#BrowseText() abort
    if cfplay#config#IsWorking()
        tabnew __Print__
        setlocal buftype=nofile
        call append(0, cfplay#text#GetText())
        setlocal readonly
        setlocal filetype=cpp
        setlocal nomodifiable
        normal gg
        nnoremap <script> <silent> <buffer> q :q<cr>:echo "quited"<cr>
        nnoremap <script> <silent> <buffer> h
                    \ :echo "'q' for quit, 'y' for yankall"<cr>
        let l:ykey = cfplay#config#YankKey()
        execute "nnoremap <script> <silent> <buffer> y " . l:ykey
    else
        echom "Currently NOT at ANY problem."
    endif
endfunction
