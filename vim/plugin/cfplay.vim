" vim: et
"
" author: lifeich1
" autoload directory: cfplay

command! CfplayOn call cfplay#ctx#Enable()
command! CfplayOff call cfplay#ctx#Disable()
command! CfplayToggle call cfplay#ctx#Toggle()

command! CfplayNewOrRenProb call cfplay#ctx#EnterNewOrRename()
command! CfplayEdit call cfplay#ctx#EnterEdit()
command! CfplayClear call cfplay#new#Clear()
command! CfplayPreview call cfplay#text#BrowseText()

let s:initcnt = get(s:, "initcnt", 0) + 1
"echom "Init cnt: " . s:initcnt

if s:initcnt > 1
    call cfplay#ctx#ReInit()
endif
