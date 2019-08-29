var
  i,j,k,n,m,l,o,q,g,tt:longint;
  a,b,v,t,va,t1:array[1..300005]of longint;
  f:array[1..300005,1..12]of longint;
begin
  assign(input,'sibyl.in');
  reset(input);
  assign(output,'sibyl.out');
  rewrite(output);
  readln(n,m,q);
  fillchar(va,sizeof(va),0);
  for i:=1 to m do
    begin
      read(a[i],b[i]);
      if a[i]<>1 then inc(v[a[i]]);
      if b[i]<>1 then inc(v[b[i]]);
    end;
  l:=1;
  for i:=2 to n do
    if v[i]>10
    then begin l:=0; break; end;
  if l=1
  then
  begin
  fillchar(t,sizeof(t),0); tt:=0;
  for i:=1 to m do
    begin
      if a[i]<>1
      then begin t[a[i]]:=t[a[i]]+1; f[a[i],t[a[i]]]:=b[i]; end
      else begin tt:=tt+1; t1[tt]:=b[i]; end;
      if b[i]<>1
      then begin t[b[i]]:=t[b[i]]+1; f[b[i],t[b[i]]]:=a[i]; end
      else begin tt:=tt+1; t1[tt]:=a[i]; end;
    end;
  for i:=1 to q do
    begin
      read(o);
      if o=1
      then begin
             read(j,k);
             va[j]:=va[j]+k;
             if j<>1
             then for g:=1 to t[j] do
                    va[f[j,g]]:=va[f[j,g]]+k
             else for g:=1 to tt do
                    va[t1[g]]:=va[t1[g]]+k;
           end
      else begin read(j); writeln(va[j]); end;
    end;
  close(input); close(output);
  end
  else
  begin
    for i:=1 to q do
      begin
        read(o);
        if o=1
        then begin
               read(j,k);
               va[j]:=va[j]+k;
               for g:=1 to m do
                 if a[g]=j
                 then va[b[g]]:=va[b[g]]+k
                 else if b[g]=j
                      then va[a[g]]:=va[a[g]]+k;
             end
        else begin read(j); writeln(va[j]); end;
      end;
    close(input); close(output);
  end;
end.