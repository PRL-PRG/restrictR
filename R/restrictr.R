create_restrictr <- function() {
  .Call(C_create_restrictr)
}

destroy_restrictr <- function(restrictr)
  invisible(.Call(C_destroy_restrictr, restrictr))

run_as_strict <- function(expr) {
  restrictr <- create_restrictr()
  result <- dyntrace(restrictr, expr)
  destroy_restrictr(restrictr)
  result
}
