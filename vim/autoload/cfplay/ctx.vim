" vim: et
"
" author: lifeich1

let s:ctx_flag = 0
let s:makeprg_store = ""
let s:cur_file = expand("<sfile>")

function! cfplay#ctx#EnableMakeEnv() abort
    if strlen(s:makeprg_store) ==# 0
        let s:makeprg_store = &makeprg
    endif
    let l:root_dir = fnamemodify(s:cur_file, ':h:h:h')
    let l:template = l:root_dir . "/templates/"
    let l:mkf = cfplay#config#TemplateMakefile()
    let &makeprg = "make -f " . l:template . l:mkf
endfunction

function! cfplay#ctx#RestoreMakeEnv() abort
    if strlen(s:makeprg_store) > 0
        let &makeprg = s:makeprg_store
        let s:makeprg_store = ""
    endif
endfunction

function! cfplay#ctx#Enable() abort
    let s:ctx_flag = 1

    " set mapping
    nnoremap <leader>pr :call cfplay#new#NewOrRename()<cr>
    nnoremap <leader>pe :call cfplay#new#TryEdit()<cr>
    nnoremap <leader>pc :call cfplay#new#Clear()<cr>
    nnoremap <leader>pp :call cfplay#text#BrowseText()<cr>

    " set makeprg
    call cfplay#ctx#EnableMakeEnv()

    echom "Enable code playground, welcome!"
endfunction

function! cfplay#ctx#Disable() abort
    " restore makeprg
    call cfplay#ctx#RestoreMakeEnv()

    if s:ctx_flag ==# 0
        return
    endif
    let s:ctx_flag = 0

    " clear mapping
    nunmap <leader>pr
    nunmap <leader>pe
    nunmap <leader>pc
    nunmap <leader>pp

    echom "Disabled playground"
endfunction

function! cfplay#ctx#Toggle() abort
    if s:ctx_flag
        call cfplay#ctx#Disable()
    else
        call cfplay#ctx#Enable()
    endif
endfunction

function! cfplay#ctx#ReInit() abort
    if s:ctx_flag
        call cfplay#ctx#Enable()
    endif
endfunction

function! cfplay#ctx#EnterNewOrRename() abort
    call cfplay#new#NewOrRename()
    call cfplay#ctx#EnableMakeEnv()
endfunction

function! cfplay#ctx#EnterEdit() abort
    call cfplay#new#TryEdit()
    call cfplay#ctx#EnableMakeEnv()
endfunction
