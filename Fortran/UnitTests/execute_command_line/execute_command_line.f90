  integer :: i, j
  character(len=100) :: msg
  character(len=:), allocatable :: command
  command='notthere'

  msg = ""

  call execute_command_line ("ls *.f90")

  print *, "-----------------------------"

  call execute_command_line ("sleep 1 ; ls *.f90", .false.)
  print *, "I'm not waiting"
  call sleep(2)

  print *, "-----------------------------"

  call execute_command_line ("sleep 1 ; ls *.f90", .true.)
  print *, "I did wait"
  call sleep(2)

  print *, "-----------------------------"

  call execute_command_line ("ls *.f90", .true., i)
  print *, "Exist status was: ", i

  print *, "-----------------------------"

  call execute_command_line ("echo foo", .true., i, j)
  print *, "Exist status was: ", i
  print *, "Command status was: ", j

  print *, "-----------------------------"

  call execute_command_line ("echo foo", .true., i, j, msg)
  print *, "Exist status was: ", i
  print *, "Command status was: ", j
  print *, "Error message is: ", trim(msg)

  print *, "-----------------------------"

  call execute_command_line ("ls *.doesnotexist", .true., i, j, msg)
  print *, "Exist status was: ", i
  print *, "Command status was: ", j
  print *, "Error message is: ", trim(msg)

  print *, "-----------------------------"

  print *, "-------------Sync------------"
  msg = ''
  call execute_command_line("notthere",               exitstat=i, cmdstat=j, cmdmsg=msg)
  if (j /= 5 .or. msg /= "Command not found with exit code: 127." ) STOP 1
  call execute_command_line("cat GeneralErrorCommand", exitstat=i, cmdstat=j, cmdmsg=msg)
  if (j /= 3 .or. msg /= "Command line execution failed with exit code: 1." ) STOP 2
  msg = "remaining buffer not modified XXXXXXXXXXXXXXXXXXX"
  call execute_command_line("touch NotExecutedCommandFile && chmod -x NotExecutedCommandFile && ./NotExecutedCommandFile", exitstat=i, cmdstat=j, cmdmsg=msg)
  if (j /= 4 .or. msg /= "Command cannot be executed with exit code: 126.XX" ) STOP 3
  msg = ''
  call execute_command_line("notthere",               exitstat=i, cmdstat=j            )
  if (j /= 5 .or. msg /= '' ) STOP 4

  print *, "------------Async------------"
  msg = ''
  call execute_command_line("notthere", wait=.false., exitstat=i, cmdstat=j, cmdmsg=msg)
  if (j /= 0 .or. msg /= '') STOP 5
  j = 123
  call execute_command_line("notthere", wait=.false., exitstat=i,            cmdmsg=msg)
  if (j /= 123 .or. msg /= '') STOP 6
  call execute_command_line("notthere", wait=.false., exitstat=i, cmdstat=j            )
  if (j /= 0 .or. msg /= '') STOP 7
  call execute_command_line("notthere", wait=.false., exitstat=i                       )
  if (j /= 0 .or. msg /= '') STOP 8
  

  end
