####################################################
# ターゲットを指定してビルドするオプション
# https://theolizer.com/cpp-school3/cpp-school3-3/
####################################################
function(option_of_exclude_from_all target_name)
    # EXCLUDE_FROM_ALL(EXCLUDE_FROM_DEFAULT_BUILD)を設定するとデフォルトビルドターゲットから外れる
    set_target_properties(${target_name} PROPERTIES
        EXCLUDE_FROM_ALL TRUE           # Makefile, Xcode
        EXCLUDE_FROM_DEFAULT_BUILD TRUE # Visual Studio (注意: target_nameが他のビルドターゲットの依存を受けいていても自動でデフォルトターゲットに追加されない)
    )
endfunction()

####################################################
# 変数リストの中身をすべて消去するオプション
####################################################
# How to: list_valiable_name(list_variable)
macro(list_variable_name)
    # マクロ外のスコープの変数を消去する
    foreach(_var IN LISTS ${ARGV})
        unset(${_var})
    endforeach()
endmacro()

