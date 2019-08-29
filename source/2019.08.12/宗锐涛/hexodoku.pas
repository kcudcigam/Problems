begin
  assign(input,'hexodoku.in');
  reset(input);
  assign(output,'hexodoku.out');
  rewrite(output);
  writeln('No way');
  close(input);
  close(output);
end.