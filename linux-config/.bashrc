# -*- sh -*-

#===============================================================================
# EXAMPLES
#===============================================================================
#
#
# find metrics/src/ -type f -regextype posix-extended -iregex ".*adjoint.*_dMetrics\.(cpp|h)"
# find metrics/ -type f -print0 | xargs -0 perl -i -pe 's/([<,] *)(Primal|FiniteD)>/\1\2_t>/'
# find ./ -type f | xargs grep "regexp"
# find . -name '*.cpp' | xargs wc -l
# find . -regextype posix-extended -iregex ".*\.(cpp|h|java)" | xargs wc -l
#
# grep -r --(include|exclude)=*.{h,cpp} "regexp" <root path>
#
#
# using perl like grep:
#
# perl -nle 'print if /pattern/' file(s)
# perl -nle 'print "$ARGV:$_" if /pattern/' file(s)
# perl -nle 'print $1 if /(pattern)/' file(s)
# perl -ni -e 'print unless /def/' test
#
#
# using perl like sed:
#
# perl -pe 's/<(\w(?:\w|<|>|,| )*) +(const),/<$2 $1,/'
#
#
#===============================================================================
# SETTINGS
#===============================================================================


if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi

PS1="\W> "

export EDITOR=emacs

alias ls="ls --color=always"
alias grep="grep --color=always -P -R"
alias less="less -R"
alias which='alias | /usr/bin/which --tty-only --read-alias --show-dot --show-tilde'
alias memcheck="valgrind --tool=memcheck --leak-check=yes --show-reachable=yes"

#shopt -s cdspell
#shopt -s cdable_vars
#shopt -s checkhash
#shopt -s checkwinsize
#shopt -s sourcepath
#shopt -s no_empty_cmd_completion
#shopt -s cmdhist
#shopt -s histappend histreedit histverify
#shopt -s extglob


#===============================================================================
# APPLICATIONS
#===============================================================================


export PATH=$HOME/bin:$PATH


#===============================================================================
# FUNCTIONS
#===============================================================================


function date_stamp
{
    echo $(date +"%Y-%m-%d")
}


function dos_to_unix
{
    perl -pi -e 's|\r\n|\n|g' $1
}


function rm_junk
{
    find $1 -name \*~ -exec rm {} \;
    find $1 -name \*.orig -exec rm {} \;
}


function mfind
{
    args=("$@")

    first_arg=${args[0]}
    last_arg=${args[$#-1]}

    f_args=""
    for ((i=0; i<$#-1; ++i)); do
        f_args="$f_args ${args[$i]}"
    done

    l_args=""
    for ((i=1; i<$#; ++i)); do
        l_args="$l_args ${args[$i]}"
    done

    find $l_args -type f -print | \grep -P -R -i "$first_arg"
}


function mdiff
{
    if test "$#" = 0; then
        (
            git diff --color
            git ls-files --modified --others --exclude-standard |
            while read -r i; do git diff --color -- /dev/null "$i"; done
        ) | `git config --get core.pager`
    else
        git diff "$@"
    fi
}


#===============================================================================
# INCLUDES
#===============================================================================


source $HOME/.bashrc-CDUK
