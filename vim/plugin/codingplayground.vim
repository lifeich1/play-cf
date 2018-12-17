" vim: et
"
" author: lifeich1
" autoload directory: cdplgnd

command! CodePlayGroundOn call cdplgnd#ctx#Enable()
command! CodePlayGroundOff call cdplgnd#ctx#Disable()
command! CodePlayGroundToggle call cdplgnd#ctx#Toggle()

command! CodePlayPreview call cdplgnd#text#BrowseText()

let s:initcnt = get(s:, "initcnt", 0) + 1
"echom "Init cnt: " . s:initcnt

if s:initcnt > 1
    call cdplgnd#ctx#ReInit()
endif
