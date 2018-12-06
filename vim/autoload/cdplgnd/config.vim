" vim: set sw=2 ts=2 et
"
" author: lifeich1
" email: lifeich0@gmail.com 

function! cdplgnd#config#EditLayout()
    return get(g:, "CodePlayground_EditLayout", "split12")
endfunction
