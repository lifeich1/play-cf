" vim: et
"
" author: lifeich1

let s:ctx_flag = 0
let s:makeprg_store = ""
let s:cur_file = expand("<sfile>")

function! cdplgnd#ctx#EnableMakeEnv() abort
    if strlen(s:makeprg_store) ==# 0
        let s:makeprg_store = &makeprg
    endif
    let l:root_dir = fnamemodify(s:cur_file, ':h:h:h')
    let l:template = l:root_dir . "/templates/"
    let l:mkf = cdplgnd#config#TemplateMakefile()
    let &makeprg = "make -f " . l:template . l:mkf
endfunction

function! cdplgnd#ctx#RestoreMakeEnv() abort
    if strlen(s:makeprg_store) > 0
        let &makeprg = s:makeprg_store
        let s:makeprg_store = ""
    endif
endfunction

function! cdplgnd#ctx#Enable() abort
    let s:ctx_flag = 1

    " set mapping
    nnoremap <leader>pr :call cdplgnd#new#NewOrRename()<cr>
    nnoremap <leader>pe :call cdplgnd#new#TryEdit()<cr>
    nnoremap <leader>pc :call cdplgnd#new#Clear()<cr>

    " set makeprg
    call cdplgnd#ctx#EnableMakeEnv()

    echom "Enable code playground, welcome!"
endfunction

function! cdplgnd#ctx#Disable() abort
    " restore makeprg
    call cdplgnd#ctx#RestoreMakeEnv()

    if s:ctx_flag ==# 0
        return
    endif
    let s:ctx_flag = 0

    " clear mapping
    nunmap <leader>pr
    nunmap <leader>pe
    nunmap <leader>pc

    echom "Disabled playground"
endfunction

function! cdplgnd#ctx#Toggle() abort
    if s:ctx_flag
        call cdplgnd#ctx#Disable()
    else
        call cdplgnd#ctx#Enable()
    endif
endfunction

function! cdplgnd#ctx#ReInit() abort
    if s:ctx_flag
        call cdplgnd#ctx#Enable()
    endif
endfunction

function! cdplgnd#ctx#EnterNewOrRename() abort
    call cdplgnd#new#NewOrRename()
    call cdplgnd#ctx#EnableMakeEnv()
endfunction

function! cdplgnd#ctx#EnterEdit() abort
    call cdplgnd#new#TryEdit()
    call cdplgnd#ctx#EnableMakeEnv()
endfunction
