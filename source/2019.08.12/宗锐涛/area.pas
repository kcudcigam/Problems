var
  i,j,k:longint;
  x,y,z,l,x1,y1,c:int64;
  f,n:array[1..100]of int64;
begin
  assign(input,'area.in');
  reset(input);
  assign(output,'area.out');
  rewrite(output);
  readln(x,y);
  x:=x+1;
  y:=y+1;
  if x>y
  then z:=x
  else z:=y;
  k:=1;
  c:=2;
  while c<z do
    begin
      c:=c*2;
      k:=k+1;
    end;
  f[1]:=1;
  n[1]:=1;
  f[2]:=5;
  n[2]:=6;
  l:=16;
  for i:=3 to k do
    begin
      f[i]:=f[i-1]*2-n[i-1]-n[i-2]+l;
      n[i]:=2*n[i-1]+l;
      l:=l*4;
    end;
  if (x=1) or (y=1)
  then begin writeln('infinity'); close(input); close(output); exit; end;
  while (x+y<2+c) or (x+y>c+c div 2+1) do
    begin
      if x>c div 2
      then x:=x-c div 2;
      if y>c div 2
      then y:=y-c div 2;
      c:=c div 2;
      if c<2
      then begin writeln('infinity'); close(input); close(output); exit; end;
      k:=k-1;
    end;
  writeln(f[k]);
  close(input);
  close(output);
end.