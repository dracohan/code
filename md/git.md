# Git 

### log with tree
>git log --oneline --decorate --graph --all
### alias
git config --global alias.la 'log --oneline --decorate --graph --all'
git config --global alias.st 'status'
git config --global alias.br 'branch'
git config --global alias.ci 'commit'
git config --global alias.co 'checkout'
<!-- >git config --global alias.st 'status' -->


### submodule check out master
>git submodule foreach --recursive "git checkout master"
