" vim: set sw=2 ts=2 et
"
" author: lifeich1

let s:ctx_flag = 0

function! cdplgnd#ctx#enable() abort
    let s:ctx_flag = 1

    " set mapping
    nnoremap <leader>pr :call cdplgnd#new#newOrRename()<cr>
    nnoremap <leader>pe :call cdplgnd#new#edit()<cr>
    nnoremap <leader>pc :call cdplgnd#new#clear()<cr>
endfunction

function! cdplgnd#ctx#disable() abort
    let s:ctx_flag = 0

    " clear mapping
    nunmap <leader>pr
    nunmap <leader>pe
    nunmap <leader>pc
endfunction

function! cdplgnd#ctx#toggle() abort
    if s:ctx_flag
        cdplgnd#ctx#disable()
    else
        cdplgnd#ctx#enable
    endif
endfunction
