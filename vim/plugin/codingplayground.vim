" vim: et
"
" author: lifeich1
" autoload directory: cdplgnd

function! g:CodePlayGroundOn()
    call cdplgnd#ctx#Enable()
endfunction

function! g:CodePlayGroundOff()
    call cdplgnd#ctx#Disable()
endfunction

function! g:CodePlayGroundToggle()
    call cdplgnd#ctx#Toggle()
endfunction

command! CodePlayPreview call cdplgnd#text#BrowseText()

let s:initcnt = get(s:, "initcnt", 0) + 1
"echom "Init cnt: " . s:initcnt

if s:initcnt > 1
    call cdplgnd#ctx#ReInit()
endif
