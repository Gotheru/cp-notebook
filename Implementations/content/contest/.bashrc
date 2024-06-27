alias res='reset'
alias r='reset'
comp () {
	F="${1%.*}"
	g++ -g "${F}.cpp" -o "${F}" -Wall -Wextra -Wshadow -Wconversion "${@:2}"
}
run () {
	F="${1%.*}"
	comp "${F}" "${@:2}" && ./"${F}"
}
all () {
	F="${1%.*}"
	comp "${F}" "${@:2}" && ./"${F}" < "${F}.in"
}