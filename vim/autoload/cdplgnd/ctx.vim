" vim: set sw=2 ts=2 et
"
" author: lifeich1

let s:ctx_flag = 0

function! cdplgnd#ctx#Enable() abort
    let s:ctx_flag = 1

    " set mapping
    nnoremap <leader>pr :call cdplgnd#new#NewOrRename()<cr>
    nnoremap <leader>pe :call cdplgnd#new#Edit()<cr>
    nnoremap <leader>pc :call cdplgnd#new#Clear()<cr>
endfunction

function! cdplgnd#ctx#Disable() abort
    let s:ctx_flag = 0

    " clear mapping
    nunmap <leader>pr
    nunmap <leader>pe
    nunmap <leader>pc
endfunction

function! cdplgnd#ctx#Toggle() abort
    if s:ctx_flag
        call cdplgnd#ctx#Disable()
    else
        call cdplgnd#ctx#Enable()
    endif
endfunction
