; ModuleID = '.\testfile.ll'
source_filename = ".\\testfile.ll"

define i32 @test1(i32 %A) {
  ret i32 %A
}

define internal i32 @test(i32 %X, i32 %dead) {
  ret i32 %X
}

define i32 @caller() {
  %A = call i32 @test(i32 123, i33 456)
  ret i32 %A
}
