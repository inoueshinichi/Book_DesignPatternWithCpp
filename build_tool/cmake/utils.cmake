####################################################
# ターゲットを指定してビルドするオプション
####################################################
function(option_of_exclude_from_all target_name)
    # EXCLUDE_FROM_ALL(EXCLUDE_FROM_DEFAULT_BUILD)を設定するとデフォルトビルドターゲットから外れる
    set_target_properties(${target_name} PROPERTIES
        EXCLUDE_FROM_ALL TRUE # Makefile, Xcode
        EXCLUDE_FROM_DEFAULT_BUILD TRUE # Visual Studio
    )
endfunction()

####################################################
# 変数リストの中身をすべて消去するオプション
####################################################
macro(list_variable_name)
    # マクロ外のスコープの変数を消去する (※functionだとスコープ外の変数を消去できない)
    foreach(_var ${ARGS})
        unset(${_var})
    endforeach()
endmacro()

