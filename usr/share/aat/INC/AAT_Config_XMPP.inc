<%
my %arg = @_;
my $tt = $arg{tooltip};
my $xmpp = AAT::XMPP::Configuration();
my ($server, $tls, $user, $pwd) = 
	($xmpp->{server}, $xmpp->{tls}, $xmpp->{user}, $xmpp->{password});
%>
<AAT:Box width="100%">
<AAT:BoxRow>
  <AAT:BoxCol>
  <AAT:Label value="Jabber(IM)" style="B" tooltip="$tt" /></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Label value="_SERVER" style="B" tooltip="$tt" /></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Entry name="xmpp_server" value="$server" size="50" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol rspan="3"><AAT:IMG name="generic_jabber" /></AAT:BoxCol>
  <AAT:BoxCol valign="top">
	<AAT:Label value="TLS" style="B" tooltip="$tt" /></AAT:BoxCol>
  <AAT:BoxCol valign="top">
  <AAT:Selector_YesNo name="xmpp_tls" selected="$tls" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol valign="top">
  <AAT:Label value="_USER" style="B" tooltip="$tt" /></AAT:BoxCol>
  <AAT:BoxCol valign="top">
  <AAT:Entry name="xmpp_user" value="$user" size="50" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol valign="top">
  <AAT:Label value="_PASSWORD" style="B" tooltip="$tt" /></AAT:BoxCol>
  <AAT:BoxCol valign="top">
  <AAT:Password name="xmpp_password" value="$pwd" size="50" /></AAT:BoxCol>
</AAT:BoxRow>
<%
if (AAT::NOT_NULL($server))
{
	my ($level, $msg) = ((AAT::XMPP::Connection_Test()) 
		? (0, "XMPP Connection is OK !") : (2, "XMPP Connection is NOT OK !"));
%>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol cspan="2"><AAT:Message level="$level" msg="$msg" /></AAT:BoxCol>
</AAT:BoxRow>
<%
}
%>
</AAT:Box>