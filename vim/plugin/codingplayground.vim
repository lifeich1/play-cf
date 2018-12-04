" vim: sw=2 ts=2 et
"
" author: lifeich1
" autoload directory: cdplgnd

function! g:CodePlayGroundOn()
    call cdplgnd#ctx#enable()
endfunction

function! g:CodePlayGroundOff()
    call cdplgnd#ctx#disable()
endfunction

function! g:CodePlayGroundToggle()
    call cdplgnd#ctx#toggle()
endfunction
