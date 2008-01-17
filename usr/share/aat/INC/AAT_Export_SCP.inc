<% my %arg = @_; %>
<AAT:Box width="$arg{width}">
<AAT:BoxRow>
	<AAT:BoxCol cspan="4"><AAT:Label value="_EXPORT_SCP" style="B"/></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:IMG name="buttons/bt_device" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_HOST" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="scp_host" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Button name="directory" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_DIRECTORY" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="scp_dir" size="40" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:IMG name="buttons/bt_user" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_USER" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="scp_user" /></AAT:BoxCol>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol cspan="2">
	<AAT:Label value="_MSG_SSH_PUBKEY_REQUIRED" color="red"/></AAT:BoxCol>
</AAT:BoxRow>
</AAT:Box>